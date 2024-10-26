# c-project-on-Periodic-table<br>
<b>Author- Prabin Chandra Gautam</b><br>

Modern Element Finder
======================

This project is a C-based console program that allows users to search for elements using various properties. 
The data is read from text files and displayed in the terminal.

Features
--------
1. Search elements by atomic number.
2. Search elements by atomic symbol.
3. Search elements by atomic name.
4. Search elements by atomic weight.
5. Display element details: Atomic number, Name, Symbol, Weight, Subgroup, Properties.

How to Run
----------
1. Clone the repository:
  
2. Compile the code:

3. Make sure these files are in the same folder:
   - elements.txt (contains all element details)
   - atsymbol.txt (list of atomic symbols)
   - atname.txt (list of element names)

4. Run the program:
  
How the Files Should Look
-------------------------
- elements.txt:
  Format: AtomicNumber, Name, Symbol, Weight, Subgroup, Properties
  Example: 1, Hydrogen, H, 1.008, Non-metal, Colorless gas

- atsymbol.txt: 
  One atomic symbol per line (must match order in elements.txt).

- atname.txt: 
  One atomic name per line (must match order in elements.txt).

Usage
-----
1. Launch the program and choose an option from the menu.
2. Input the required search information (atomic number, symbol, name, or weight).
3. If found, the element details will be displayed.
4. Choose 'Quit' to exit the program.

Known Issues
------------
- Make sure data in elements.txt, atsymbol.txt, and atname.txt are properly aligned.
- Atomic weight search requires an exact match, which may be tricky due to decimal precision.

Future Improvements
-------------------
- Support partial search (fuzzy matching).
- Improve weight matching to handle small decimal differences.
- Add a graphical user interface (GUI).

Contributing
------------
Feel free to open issues or submit pull requests.
