ofxQt
=====================================


Introduction
------------

License
-------
[MIT License](https://en.wikipedia.org/wiki/MIT_License)

Installation
------------

- Install Qt, let it fall at the default folder (c:\Qt)
- In VS, extensions: install Qt VS Tool.

### How to turn an PG generated project to a Qt project (Visual Studio): 
- Run Project generator and add Qt addon.
- open .vcxproj file and modify the tag:

>     <PropertyGroup Label="Globals">
>     <Keyword>Win32Proj</Keyword>

to :

>     <PropertyGroup Label="Globals">
>     <Keyword>Qt4VSv1.0</Keyword>

- Right click on project, Convert to Qt VS Tool project
- Select project properties/C++/General and add:

> $(QTDIR)\include\;$(QTDIR)\include\QtCore;$(QTDIR)\include\QtGui;$(QTDIR)\include\QtOpenGL;$(QTDIR)\include\QtUiTools;$(QTDIR)\include\QtWidgets;.\GeneratedFiles;..\src\;

- Right click on project\properties\Linker and add:

**General\Additional Library Directories:**
> $(QTDIR)\lib

**Input\Additional dependencies:Debug:**
> Qt5Cored.lib;Qt5Guid.lib;Qt5OpenGLd.lib;opengl32.lib;glu32.lib;Qt5UiToolsd.lib;Qt5Widgetsd.lib;%(AdditionalDependencies)

**Release:**
> Qt5Core.lib;Qt5Gui.lib;Qt5OpenGL.lib;opengl32.lib;glu32.lib;Qt5UiTools.lib;Qt5Widgets.lib;%(AdditionalDependencies)

- If you get linker errors its because Qt VS extension is not really good. Try deleting all generated files, both in the phisical HD and in the VS project. Also the following folders. 

>     bin\
>     obj\
>     GeneratedFiles\

Also remove the .ui files from the project and add them again, this must add a custom pre build step runner by Qt compiler. It turns ObjectName.ui files to ui_ObjectName.h files. Then build again. Good "luck"!


Dependencies
------------
- Qt
- ofxGUI (examples only)

Compatibility
------------


Known issues
------------

Version history
------------


Screenshots
------------
![Image of Of_inside_Qt](https://raw.githubusercontent.com/jordiexvision/ofxQt/blob/master/screenshots/Of_inside_Qt.png)

![Image of ofAppQtWindow](https://raw.githubusercontent.com/jordiexvision/ofxQt/blob/master/screenshots/ofAppQtWindow.png)
