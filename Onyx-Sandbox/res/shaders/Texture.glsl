
#type vertex
#version 330 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_VertColor;
layout(location = 2) in float a_TextID;
layout(location = 3) in vec2 a_TextureCoord;

uniform mat4 u_ViewProjection;

out DATA
{
	vec4 v_Color;
	vec2 v_TexCoord;
	float v_TextureIndex;
} vs_out;

void main() {
	
	vs_out.v_Color = a_VertColor;
	vs_out.v_TexCoord = a_TextureCoord;
	vs_out.v_TextureIndex = a_TextID;
	
	gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core
layout (location = 0) out vec4 color;

in DATA
{
	vec4 v_Color;
	vec2 v_TexCoord;
	float v_TextureIndex;
} fs_in;

uniform sampler2D u_Textures[32];

void main() {


	vec4 texColor = fs_in.v_Color;
	vec2 v_TexCoord = fs_in.v_TexCoord;

	switch(int(fs_in.v_TextureIndex))
	{
		case 0: texColor *= texture(u_Textures[0], v_TexCoord); break;
		case 1: texColor *= texture(u_Textures[1], v_TexCoord); break;
		case 2: texColor *= texture(u_Textures[2], v_TexCoord); break;
		case 3: texColor *= texture(u_Textures[3], v_TexCoord); break;
		case 4: texColor *= texture(u_Textures[4], v_TexCoord); break;
		case 5: texColor *= texture(u_Textures[5], v_TexCoord); break;
		case 6: texColor *= texture(u_Textures[6], v_TexCoord); break;
		case 7: texColor *= texture(u_Textures[7], v_TexCoord); break;
		case 8: texColor *= texture(u_Textures[8], v_TexCoord); break;
		case 9: texColor *= texture(u_Textures[9], v_TexCoord); break;
		case 10: texColor *= texture(u_Textures[10], v_TexCoord); break;
		case 11: texColor *= texture(u_Textures[11], v_TexCoord); break;
		case 12: texColor *= texture(u_Textures[12], v_TexCoord); break;
		case 13: texColor *= texture(u_Textures[13], v_TexCoord); break;
		case 14: texColor *= texture(u_Textures[14], v_TexCoord); break;
		case 15: texColor *= texture(u_Textures[15], v_TexCoord); break;
		case 16: texColor *= texture(u_Textures[16], v_TexCoord); break;
		case 17: texColor *= texture(u_Textures[17], v_TexCoord); break;
		case 18: texColor *= texture(u_Textures[18], v_TexCoord); break;
		case 19: texColor *= texture(u_Textures[19], v_TexCoord); break;
		case 20: texColor *= texture(u_Textures[20], v_TexCoord); break;
		case 21: texColor *= texture(u_Textures[21], v_TexCoord); break;
		case 22: texColor *= texture(u_Textures[22], v_TexCoord); break;
		case 23: texColor *= texture(u_Textures[23], v_TexCoord); break;
		case 24: texColor *= texture(u_Textures[24], v_TexCoord); break;
		case 25: texColor *= texture(u_Textures[25], v_TexCoord); break;
		case 26: texColor *= texture(u_Textures[26], v_TexCoord); break;
		case 27: texColor *= texture(u_Textures[27], v_TexCoord); break;
		case 28: texColor *= texture(u_Textures[28], v_TexCoord); break;
		case 29: texColor *= texture(u_Textures[29], v_TexCoord); break;
		case 30: texColor *= texture(u_Textures[30], v_TexCoord); break;
		case 31: texColor *= texture(u_Textures[31], v_TexCoord); break;
	}
	color = texColor;
	

	
}