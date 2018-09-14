#ifndef VOLUMETRIC_FOG_H_
#define VOLUMETRIC_FOG_H_

float volumetric_fog_texture_z_to_world(float texture_z, float slice_z_log2_scale)
{
	float world_z = exp2(texture_z / slice_z_log2_scale) - 1.0;
	return world_z;
}

mediump vec4 sample_volumetric_fog(sampler3D FogVolume, mediump float world_z, mediump float slice_z_log2_scale)
{
    mediump float texture_z = log2(1.0 + world_z) * slice_z_log2_scale;
    return textureLod(FogVolume, vec3(gl_FragCoord.xy, texture_z), 0.0);
}

#endif