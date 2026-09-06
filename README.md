*This project has been created as part of the 42 curriculum by zkarman, kzhu*

**Description**

This project aims to put into practice the concept of raycasting. To complete this project the work was divided into two parts. The parsing was done by zkarman, and then the raycasting by kzhu.

Parsing:

The parsing of this project was done by reading the .cub file from top to bottom in one go. The wall textures, and the floor and ceiling colors can be arranged in any order in the .cub file, as long as the grid map is parsed last. 

The program looks for specific identifiers in order to assign the appropriate textures where they need to go (i.e. NO, SE, EA, WE, F, C). Once an identifier is found, the following file path or color scheme is then assigned to the appropriate struct within the project.

Afterwards, the grid map is parsed, flood-filled, and validated before continuing on with the program. 

**Instructions**

To compile the project, run make. To run the program, run the executable along with one of the maps in the MAPS folder.

ex: ./cub3D MAPS/...

**Resources**

https://hackmd.io/@nszl/H1LXByIE2