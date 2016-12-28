// RUN: %dxc -E main -T ps_5_0 %s | FileCheck %s

// CHECK: min16f
// CHECK: min16u
// CHECK: min16i
// CHECK: min16i
// CHECK: fadd float
// CHECK: fadd float

precise float4 main(min10float4 a : A, min16uint b : B, min16int c : C, min12int d : D) : SV_Target
{
    precise float t = 2.f;
    precise float4 t2 = a + t + (min10float)2.f;
    return t2+3;
}
