1 .כותרת.
-2 .פרטי הסטודנט: שם מלא כפי שהוא מופיע ברשימות המכללה, ת"ז.
-3 .הסבר כללי של התרגיל.
4 .רשימה של הקבצים שיצרנו, עם הסבר קצר )לרוב לא יותר משורה או שתיים( לגבי תפקיד
הקובץ.
5 .מבני נתונים עיקריים ותפקידיהם.
-6 .אלגוריתמים הראויים לציון.
7 .באגים ידועים.
8 .הערות אחרות.
יש לתמצת ככל שניתן אך לא לוותר על אף חלק. אם אין מה להגיד בנושא מסוים יש להשאיר את
הכותרת ומתחתיו פסקה ריקה. נכתוב ב־README כל דבר שרצוי שהבודק ידע כשהוא בודק את
התרגיל

/////////////////////////////////////////////////////////////////////
OOP1 ex1

Written by: Tali Kalev (טלי כלב), ID:208629691, Login: talikal
            Noga Levy (נוגה לוי), ID:315260927, Login: levyno

General Description of the Exercise:
    In this exercise we were requested to implement 4 objects of simple geometric shapes; Rectangle, Square,
    Equilateral triangle and Hourglass. The main program uses these objects and draws them out on the screen.

Files that were Created:
    1. Rectangle.cpp and the corresponding header file Rectangle.h
    2. Square.cpp and the corresponding header file Square.h
    3. Triangle.cpp and the corresponding header file Triangle.h
    4. Hourglass.cpp and coresponding header file Hourglass.h
        
    In each .h file created, classes were declared of the according geometric figure
    along side function prototypes that allowed access to data involving the geometric figures.

Main Data Structures and their Jobs:
    1. Rectangle Class contains functions that create a rectangle whose base is parallel to the x axis.
        The class also defines members that hold the rectangle's characteristics.
    2. Triangle Class contains functions that create an equilateral triangle whose base is parallel to the x axis.
        The class also defines members that hold the triangles characteristics.
    3. Square Class contains functions that make use of the Rectangles class' creating functions.
        The class also defines members that hold data of a rectangle with 4 equal sides.
    4. Hourglass Class contains functions that make use of the Triangle class' creating functions.
        The class also defines members the hold the data of 2 equilateral triangles (one upward facing and one downward facing).







