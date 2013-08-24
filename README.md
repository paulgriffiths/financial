financial
=========

What is it?
-----------

**financial** is a C++ financial library. Functionality includes:
* Calculating present and future values
* Calculating loan repayments
* Calculating sinking fund payments
* Valuing annuities and perpetuities

Who maintains it?
-----------------
**financial** is written and maintained by Paul Griffiths.

The latest version
------------------
Details of the latest version can be found on the GitHub project page at
<https://github.com/paulgriffiths/financial>.

Documentation
-------------
Up-to-date documentation can be found at
<https://github.com/paulgriffiths/financial/wiki>.


Installation
------------
**financial** is written in C++.

Download the source code and edit the file `Makefile` to modify the
following variables:
* LIB_INSTALL_PATH
* INC_INSTALL_PATH

with the directories to which to install the library and the header files,

From the command line, run `make` and then `make install` to deploy the
library and header files. Run `make sample` to build an example program
with the installed library. `#include <paulgrif/financial.h>` to use the
library.

Licensing
---------
Please see the file called LICENSE.

Contacts
--------
* If you have a concrete bug report for **financial** please go to the GitHub
issue tracker at <https://github.com/paulgriffiths/financial/issues>.
