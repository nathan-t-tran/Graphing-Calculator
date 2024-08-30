# Graphing-Calculator

//

This project is a fully developed Graphing Calculator that was built from the ground up using a combination of multiple classes and functions, leveraging the SFML (Simple and Fast Multimedia Library) for graphical rendering, and implementing the Shunting Yard algorithm along with Reverse Polish Notation (RPN) for parsing and evaluating mathematical expressions. The purpose of this project was to create an intuitive, user-friendly calculator that not only performs standard arithmetic but also graphs functions with high precision.

The core of this Graphing Calculator is structured around several key components. First, SFML was utilized for rendering the graphical interface, which includes drawing axes, plotting points, and dynamically adjusting the viewing window. SFML's robust capabilities allowed for smooth interactions and real-time updates to the graph as the user inputs different functions and parameters.

To handle the complex task of parsing mathematical expressions input by the user, the Shunting Yard algorithm was implemented. This algorithm efficiently converts infix expressions, which are familiar to most users (e.g., 3 + 4 * 2), into a format that is easier for the program to evaluate—Reverse Polish Notation (RPN). The RPN algorithm then takes over, evaluating the expression in a manner that naturally handles the order of operations without requiring parentheses, thereby ensuring the correctness and consistency of calculations.

The project was developed by carefully constructing multiple classes and functions from scratch, each serving a specific role in the overall system. These classes include components for managing mathematical expressions, handling user input, controlling the graphical output, and managing the state of the calculator. The modularity of the codebase allows for easy expansion and modification, making it straightforward to add new features or improve existing ones.

In summary, this Graphing Calculator project showcases the integration of SFML for graphical rendering, the Shunting Yard algorithm for expression parsing, and RPN for efficient calculation. The system was built with a strong emphasis on clean code architecture and modular design, resulting in a powerful tool capable of handling complex mathematical operations and visualizing them in real-time. This project reflects a deep understanding of both the theoretical and practical aspects of computer science, combining advanced algorithms with hands-on application development.

//