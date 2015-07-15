#version 120

void main(){
	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex; // == ftransform()
	gl_FrontColor = gl_Color;
}
