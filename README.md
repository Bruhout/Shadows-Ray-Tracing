# Shadows-Ray-Tracing
Explaining a way to create sharp shadows in a ray tracing renderer

This is a ray tracer made with inspiration from the simple ray tracing application developed in the book "Ray Tracing In One Weekend" by Peter Shirley.
A lot of the functionality like different material is missing here as the goal is just to show how shadows can be rendered.

Preface: The rendered scenes are stored as .ppm images. It is probably the simple kind of image format, which just contains some metadata about image resolution and color depth and then a bunch of RGB values written in plain text. To unerstand how a .ppm file works, go through the .ppm image files in ```/rendered``` with a text editor. I order to view a .ppm image as well, an actual image you will need an image viewer that supports the file format. The default image viewer on ubuntu supports .ppm images.

The basic algorithm is simple. A scene is defined with the objects that are present in it (for now, we only have spheres for convenience). A camera and a viewport is placed in the scene. Imaginary 'Rays' are fired starting from the camera through the viewport, one ray per pixel. The rays extend through the scene until they hit an object (or go out of bounds).

If the ray hits an object, we know that the camera will see that object through the current pixel (the one which the ray was fired through). So this pixel can be coloured in. Any other pixels are simply giving a gray color, and hit pixels are given a purple color (just because I like purple). This is what the render of the scene looks like right now. We just have 2 differently sized spheres in the scene.

The scene looks something like this, as of now.


![NSAA](https://github.com/Bruhout/Shadows-Ray-Tracing/assets/147948392/bf77168d-aca7-4a65-b53a-35520714b064)


Yes, it lacks any kind of shading. Lets add a light source.
The light source is a point bulb like thingy at the coordinates (1000 , 1000 , 1000). Its placed very far from the scene because the model of shading we will be using is terrible and looks very unnatural at small distances, perhaps because we lack any kind of ambient lighting.

Now when the ray hits an object, we will retreive some relevant data, stored in an object of the ```HitRecord``` class. One of these data members is the surface normal, or the arrow pointing straight up from the surface of the object.
Based on this, we will shade the sphere. If that point is facing the light source, its coloured brightly, the further away it faces, the darker the face gets.
Yes, I know its not a good shading model. But this is what we have now.


![NOSHADOW](https://github.com/Bruhout/Shadows-Ray-Tracing/assets/147948392/b5121f0b-e037-4fc1-906f-caecbf58ad41)
