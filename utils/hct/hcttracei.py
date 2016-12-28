#!/usr/bin/env python2.7
# Copyright (C) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license. See COPYRIGHT in the project root for full license information.

"""Analyses the ETW dump file fors dxcompiler output as generated by hcttrace."""

import argparse
import datetime
import xml.etree.ElementTree as ET

# Task values.
DXCompilerInitialization = 1;
DXCompilerShutdown = 2;
DXCompilerCreateInstance = 3;
DXCompilerIntelliSenseParse = 4;
DXCompilerCompile = 5;
DXCompilerPreprocess = 6;
DXCompilerDisassemble = 7;

# Opcode values
OpcodeStart = 1;
OpcodeStop = 2;

# Namespace dictionary.
ns = {'e': 'http://schemas.microsoft.com/win/2004/08/events/event'}

def write_basic_info(node):
    '''Writes computer information'''
    print("Basic information:")
    print("CPU Speed: %s" % node.find("e:Data[@Name='CPUSpeed']", ns). text)
    print("Processor count: %s" % node.find("e:Data[@Name='NumberOfProcessors']", ns). text)
    print("Events lost: %s" % node.find("e:Data[@Name='EventsLost']", ns). text)
    print("Pointer size: %s" % node.find("e:Data[@Name='PointerSize']", ns). text)


def write_compile_times(root):
    '''Prints out compilation times.'''
    compilations = {}
    for e in root:
        system_node = e.find("e:System", ns)
        if system_node is None:
            continue
        channel = system_node.find("e:Channel", ns)
        if channel is None or channel.text <> "Microsoft-Windows-DXCompiler-API/Analytic":
            continue
        task = int(system_node.find("e:Task", ns).text)
        opcode = int(system_node.find("e:Opcode", ns).text)
        pid = int(system_node.find("e:Execution", ns).attrib['ProcessID'])
        tid = int(system_node.find("e:Execution", ns).attrib['ThreadID'])
        time_created = system_node.find("e:TimeCreated", ns).attrib['SystemTime']
        # Something like:
        # 2016-02-02T00:10:51.619434100Z
        # Unfortunately datetime doesn't have enough precision, so we make do with this:
        # 2016-02-02T00:10:39.630081
        if task == DXCompilerCompile:
            time_created = time_created[:26]
            cid = '{0},{1}'.format(pid, tid)
            parsed_time_created = datetime.datetime.strptime(time_created, "%Y-%m-%dT%H:%M:%S.%f")
            if opcode == OpcodeStart:
                #print "Start at %s" % time_created
                compilations[cid] = parsed_time_created
            else:
                old_parsed_time_created = compilations[cid]
                print "Compilation took %s" % str(parsed_time_created - old_parsed_time_created)


def main():
  parser = argparse.ArgumentParser(description=__doc__)
  parser.add_argument('-v', '--verbose', action='store_true',
                      help='Show verbose output')
  parser.add_argument('dumpfiles', nargs='+')
  args = parser.parse_args()

  for dumpfile in args.dumpfiles:
    if args.verbose:
      print >>sys.stderr, 'Scanning for dxcompiler events in dumpfile: %s' % (dumpfile,)
    tree = ET.parse(dumpfile)
    root = tree.getroot()
    write_basic_info(root.find('e:Event/e:EventData', ns))
    write_compile_times(root)
    # Other interesting things:
    # errors, working set, additional stats

if __name__ == '__main__':
  main()
