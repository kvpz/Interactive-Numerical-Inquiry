## Interactive Numerical Inquiry 
A desktop app designed with the idea to facilitate the learning process
for students studying numerical methods & analysis. To accomplish this, development
efforts are focused on the UX/UI instead of the actual implementation of the methods.
The application should allow the user to:
- views dedicated a type of problem (such that only some numerical methods apply)
- the option to select a numerical method 
- explicit & detailed output containing the solution or error messages
- output visualization
- database to store data (input, output, method names, etc)

It is developed with Qt 5.7 Quick Controls 2 under a Windows environment. 
### Features
- Bisection method
- Gaussian elimination

### Workflow & Style Guide
[Git Style Guide](https://github.com/agis-/git-style-guide)

### Software Specifications

#### API & Frameworks
I'm currently having issues making a shared library out of the TNT/JAMA libraries. [Creating Qt shared libraries](http://doc.qt.io/qt-5/sharedlibrary.html)
documentation offers a "how-to" guide. I'm looking for a better way than to implement the Symbols
required to make a shared library (using TNT files and others). For now, the current TNT library files
will be under the same project directory.

**Template Numerical Toolkit (TNT)** (visit the [TNT Website](http://math.nist.gov/tnt/) for more details)
- Used to solve systems of equations

#### Why use Qt Quick Controls 2?
There is a performance boost over Quick Controls 1 because user interface objects
are *lighter* and C++ is used instead of QML to handle events.
[Quick Controls 1 & 2 Comparison](http://doc.qt.io/qt-5/qtquickcontrols2-differences.html)