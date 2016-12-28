// RUN: %dxc -E main -T ps_5_0 %s

float3 main(float4 a : A, float4 b : B) : SV_Target
{
  float3 r = 0;
  r += dot(a, b);
  r += dot(a.wyz, b.wyz);
  r += dot(a.zz, b.xy);
  return r;
}
