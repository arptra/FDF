# FDF  
  
This project is about creating a simplified graphic “wireframe” (“fils de fer” in french,hence the name of the project) representation of a relief landscape linking various points(x, y, z)via segments. The coordinates of this landscape are stored in a file passed as a parameter to your program. Here is an example of map file (`cat AblH.fdf`):  

![Alt image](https://github.com/arptra/FDF/blob/master/map_fdf.png)  
  
  Each number corresponds to a point in space:
  - The horizontal position corresponds to its axis.
  - The vertical position corresponds to its ordinate.
  - The value corresponds to its altitude  
  
# Run FDF
`./fdf AblH.fdf`  

![Alt Text](https://github.com/arptra/FDF/blob/master/demo_fdf.gif)
