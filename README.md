## CUB3D

2d raycast: 
1. Set Up Your Development Environment

2. Initialize the Screen
Define constants such as screenWidth, screenHeight, mapWidth, and mapHeight.
Set up the worldMap as a 2D array to represent the game world.
Initialize the MLX window using mlx_init() and mlx_new_window() with the specified width and height.
1. Read map
2. Test map
________________

A valid map / config file obeys the following rules:
1. The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.
2. The map must be closed/surrounded by walls
3. Except for the map content, each type of element can be separated by one or more empty line(s).
4. Except for the map content which always has to be the last, each type of element can be set in any order in the file.
5. Except for the map, each type of information from an element can be separated
by one or more space(s).
6. The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.

DDA 



3. Set Up Player and Camera
Define the player's starting position (posX, posY) and direction (dirX, dirY).
Set up the camera plane (planeX, planeY) to define the field of view.

4. Implement Raycasting Logic
For each vertical stripe on the screen, calculate the ray's direction based on the player's direction and the camera plane.
Use the Digital Differential Analyzer (DDA) algorithm to determine the intersection of the ray with the map grid.
Compute the perpendicular distance to the wall to avoid fisheye effects.
Calculate the height of the wall slice to be rendered based on this distance.

5. Render the Scene
Use MLX functions like mlx_pixel_put() or draw to an image buffer with mlx_put_image_to_window() to render vertical lines representing the walls.
Assign different colors to the walls based on the worldMap values and apply shading based on whether the wall is hit from the side.

6. Handle User Input
Use MLX's input handling functions (mlx_key_hook, mlx_hook, etc.) to manage player movement (forward, backward) and rotation (left, right).
Update the player’s position and direction based on the keys pressed.

7. Implement Frame Timing
Calculate the frame time to adjust movement and rotation speeds.
Optionally, display the FPS (frames per second) by calculating it from the frame time.

8. Loop and Refresh
Set up the main loop using mlx_loop().
Continuously clear the screen, render the scene, and handle input in each iteration.

9. Test and Debug
Compile and run your program, checking for correct rendering, movement, and collision detection.
Debug issues related to raycasting calculations or screen rendering.

10. Optimize and Enhance (Optional)
Optimize the performance by refining calculations and managing resources efficiently.
Consider adding advanced features like textured walls, dynamic lighting, or more complex maps to enhance the raycaster.
This plan should guide you through implementing a flat raycaster using C and the MLX library.


