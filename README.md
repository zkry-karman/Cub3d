*This project has been created as part of the 42 curriculum by zkarman, kzhu*

**Description**

This project aims to put into practice the concept of raycasting. To complete this project the work was divided into two parts. The parsing was done by zkarman, and then the raycasting by kzhu.

Parsing:

The parsing of this project was done by reading the .cub file from top to bottom in one go. The wall textures, and the floor and ceiling colors can be arranged in any order in the .cub file, as long as the grid map is parsed last. 

The program looks for specific identifiers in order to assign the appropriate textures where they need to go (i.e. NO, SE, EA, WE, F, C). Once an identifier is found, the following file path or color scheme is then assigned to the appropriate struct within the project.

Afterwards, the grid map is parsed, flood-filled, and validated before continuing on with the program.

Raycasting:

There are several steps to turn our 2D map into a 3D-looking first-person view.

1. player setup
By the giving player direction, we need to setup the player direction and plane, in this way we would have a whole field of view from the player to the direction it face.
2. redner rays
Depenging on the plane, we need to render a ray fan from the player to the plane, thus we know the direction of each ray based on the player direction and camera plane (ray->dir_x and ray->dir_y) to help the next DDA procedure.
3. DDA preparation 
We now need to prepare step_x and step_y (to figure out which neighboring cell to enter, left or right?), delta_dist_x and delta_dist_y (spcing along the ray's progress between successive X), side_dist_x and side_dist_y (the ray's progress to next X and Y boundary).
4. DDA
By comparing side_dist_x and side_dist_y, we would know which boundary does the ray crosses next, until we reached a wall cell, then we assign wall_type to the wall, in addition to the step_x and y, help us understand which type of wall the ray hit at the end, so we can draw the textue for each wall.
Then we need to caculate the wall_hit to understand in which cordinate the ray actually hit at the end, then remove the integer part so we know how many percentage of the way across this particular wall tile.
And finally we draw the line, depending on the wall dist and the wall type, start drawing it (using tex_x and tex_y to find the correct pixel inside the already selected wall texture) on the screen with the center base (HEIGHT / 2), We use wall_dist to calculate line_height, so closer walls look taller and farther walls look shorter.
5. player movement
Finally we made the player moving by pressing key A/D/W/S, after each position change, we render the whole frame again, on top of that, we added the bonus feature where you can rotate the viewing direction by moving the mouse, the frame also will be rendered again after each mouse movement.

**Instructions**

To compile the project, run make. To run the program, run the executable along with one of the maps in the MAPS folder.

ex: ./cub3D MAPS/...

**Resources**
cub3d project introduction
https://hackmd.io/@nszl/H1LXByIE2

Super Fast Ray Casting in Tiled Worlds using DDA 
https://www.youtube.com/watch?v=NbSee-XM7WA&t=452s

AI tools were used during the development of this project mainly as a learning and debugging aid. They helped explain raycasting concepts, DDA logic, MiniLibX behavior, texture mapping, and some C-related issues when we were stuck.
