# Shadows-Ray-Tracing
Explaining a way to create sharp shadows in a ray tracing renderer

This is a ray tracer made with inspiration from the simple ray tracing application developed in the book "Ray Tracing In One Weekend" by Peter Shirley.
A lot of the functionality like different material is missing here as the goal is just to show how shadows can be rendered.

Preface: The rendered scenes are stored as .ppm images. It is probably the simple kind of image format, which just contains some metadata about image resolution and color depth and then a bunch of RGB values written in plain text. To unerstand how a .ppm file works, go through the .ppm image files in ```/rendered``` with a text editor. I order to view a .ppm image as well, an actual image you will need an image viewer that supports the file format. The default image viewer on ubuntu supports .ppm images.

The basic algorithm is simple. A scene is defined with the objects that are present in it (for now, we only have spheres for convenience). A camera and a viewport is placed in the scene. Imaginary 'Rays' are fired starting from the camera through the viewport, one ray per pixel. The rays extend through the scene until they hit an object (or go out of bounds).

If the ray hits an object, we know that the camera will see that object through the current pixel (the one which the ray was fired through). So this pixel can be coloured in. Any other pixels are simply giving a gray color, and hit pixels are given a purple color (just because I like purple). This is what the render of the scene looks like right now. We just have 2 differently sized spheres in the scene.
