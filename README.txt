OOP1 ex1 - Implementation of Geometric Shapes

Written by: Tali Kalev (טלי כלב), ID:208629691
            Noga Levy (נוגה לוי), ID:315260927

General Description of the Exercise:
    In this exercise we were requested to implement 4 objects of simple geometric shapes; Rectangle, Square,
    Equilateral triangle and Hourglass. The main program uses these objects and draws them out on the screen.

Files that were Created:
    1. Rectangle.cpp and the corresponding header file Rectangle.h
    2. Square.cpp and the corresponding header file Square.h
    3. Triangle.cpp and the corresponding header file Triangle.h
    4. Hourglass.cpp and coresponding header file Hourglass.h
        
    In each header file created, classes were declared of the according geometric figure
    along side function prototypes that allowed access to data involving the geometric figures.
    All header files are located in the include folder and all source files are located in the src folder.

Main Data Structures and their Jobs:
    1. Rectangle Class contains functions that create a rectangle whose base is parallel to the x axis.
        The class also defines members that hold the rectangle's characteristics.
    2. Triangle Class contains functions that create an equilateral triangle whose base is parallel to the x axis.
        The class also defines members that hold the triangles characteristics.
    3. Square Class contains functions that make use of the Rectangles class' creating functions.
        The class also defines members that hold data of a rectangle with 4 equal sides.
    4. Hourglass Class contains functions that make use of the Triangle class' creating functions.
        The class also defines members the hold the data of 2 equilateral triangles (one upward facing and one downward facing).
    5. Vertex structure contains x and y coordinate values that presents themselves on the board.
        The structure also contains functions that help in the comparison between two vertices and checking that 
        there are on the board.
    6. Board class contains   


    No notable algorithms were implemented in this program.

    There are no known bugs in this program.

    Additional Notes:
        In the Vertex.h file and subsequently Vertex.cpp a helper function was added to compare between to vertices.








