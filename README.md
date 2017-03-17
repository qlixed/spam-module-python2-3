# spam-module-python2-3
The basic example of the spam module that works in python2 or in python3, depends of which one use to build it.

Created to:
 - Understand the differences within the python2 and python3 versions of the python-c api
 - Check how to create a module compatible with python2 and python3.

The related repos:  
spam-module-python2: https://github.com/qlixed/spam-module-python2 - Python 2 only.  
spam-module-python3: https://github.com/qlixed/spam-module-python3 - Python 3 only.  
spam-module-python2-3: https://github.com/qlixed/spam-module-python2-3 - Python 2 and Python 3 compatible.  


# How to build:

For python2:  
python2 setup.py build  

For python3:  
python3 setup.py build  

Change 'build' for 'install' to, well for the lack of better words, install it.  
If you want to record the installed files you can add after install "--record uninstall-[python version].txt" and for a clean up of the example module you can just run **uninstall.sh**.  
Curretly the uninstall-2.txt and uninstall-3.txt have the files that get installed when you install this modules system-wide.  
Also you can make a virtualenv and when you're done you can remove it.  
