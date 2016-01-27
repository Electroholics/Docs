WinSpice3
---------

This is a port of Berkeley Spice3F5 to Win32.  The program works on
Windows 95 and hopefully it should run on Windows NT also although I
have no means of testing this.

For those people who are using Windows 3.1 or just plain MSDOS, I
have a version of Spice3F5 which uses a DOS extender under plain
MSDOS but still runs in a Windows 3.1 DOS window.  Let me know if
this would be useful (send an email to mike@willingham.demon.co.uk).

I have to apologise for the way WinSpice3 works.  It is a very simple
port - partly because the effort I can apply is limited and partly
because I am not the worlds most experienced Windows programmer.  It
uses a command line interface within a window and only really uses
windows to display plots.  It is my intention to add schematic entry
of circuits and improve the integration with windows in future.

Documentation on WinSpice3 can be found in the 'doc' directory.  This
is in Word97 format (you can get a viewer from the Microsoft web page
if you don't have access to Word97).  There is also a tutorial document
and sample circuits in the 'tutorial' directory (also in Word97 format).

WinSpice3 contains all Spice3 built in devices and models with no
restrictions on memory usage.  If you find this program useful,
please send me an email or postcard with any bugs found or
suggestions.

Finally, for those people too impatient to read the docs, start up
WinSpice3 and then type 'demo' followed by the Enter key.  This will
run a script which analyses some demo circuits plotting graphs as it
goes.

Have fun!

Mike Smith
23rd July 1998
mike@willingham.demon.co.uk

Postcards to:-  35 Rampton End
                Willingham
                Cambridge
                Cambridgeshire
                England
                CB4 5JB


Some other notes
----------------

*****************************
For WinSpice3 v0.1 onwards:-
*****************************

1. There is an item on the plot window system menu to copy the
contents of a plot window to the clipboard.  This lets you load plot
graphics into word processor documents.

2. This port fixes lots of severe memory management problems which
existed in the original code.  These cause lots of crashes when I
first compiled the code.  It now seems quite stable.

3. The scripting language (based on the Unix C-Shell) now works as
advertised.  The original Berkeley code contained a fundamental
error, duplicated about 100 times in the code, which meant that this
feature does not work on most, if not all ports of Spice3.  However,
scripts now work as advertised in the documentation.

4. I have added support for the POLY statement from Spice2 so that
many device models from Spice2 and PSpice, particularly opamp macro
models, can still be used.  POLY has been replaced by an expression
in Spice3 so what happens is that in WinSpice3 the POLY statements
are expanded to a Spice3 expression before the circuit is analysed.

5. I have added support for libraries of concatenated models as
used by PSpice.  This is done by using the .lib directive in the .cir
files.  WinSpice3 searches for any unresolved models in the file
specified on the .lib file and extract the required model lines
before the circuit is analysed.

6. A separate pre-processor, capable of performing model library
searches and POLY statement expansion is also provided (spicepp.exe). 
This program is essentially embedded in the WinSpice3 executable. 
However, having a separate pre-processor is handy sometimes.

7. There are loads of demo circuits in the examples directory. Some
illustrate the use of the scripting language to perform quite complex
tasks with very little effort (see examples\bjt.cir forexample).


*****************************
For WinSpice3 v0.2 onwards:-
*****************************

8. There is a new spec command supplied by Anthony Parker 
(anthonyp@sr.hp.com).  I haven't yet worked out how to use it, but
if you type 'oldhelp spec' you get some hints.  I will include this
command in the documentation ASAP.

9. WinSpice3 includes the BSIM3 and BSIM3SOI models.  Problem is,
they don't work yet so don't bother trying.  The drain-source current
always comes out as zero when I run the supplied tests - anyone have
any ideas?

10. Plot windows and the terminal window can now be resized by
dragging the borders.

11. WinSpice2 includes a new level 2 JFET model (also by Anthony
Parker, anthonyp@sr.hp.com).  Again, no details in the User Guide
yet.

12. WinSpice3 no longer hogs the processor when waiting for keyboard
input (thanks to Horacio Gonzalez for pointing this out).

13. The 'cd' command no longer crashes if typed on its own (thanks to
Sparc Han for reporting this).  It now displays the current directory.

14. The plot windows now have a print option on the system menu (click
the top left corner of the window.  The Print Setup option still doesn't
work though.


*****************************
For WinSpice3 v0.3 onwards:-
*****************************

15. The 'spec' command has been added to the User Manual.

16. The BSIM3 and BSIM3SOI models now work.

17. Fixed a problem with parsing the .cir file when looking for POLY
directives to expand.  The POLY directives were not getting expanded.

18. Plot windows and the terminal window now have menus.  Circuits can be
loaded and run using the 'File'/'Open' menu sequence in the terminal
window.

19. Editorial changes to the User Manual have been made.  Added a description
of program installation and use at the head of the document.  Removed all
references to command completion.


After installation, the following files will have been installed:-

WSPICE3.EXE             The simulator.
HELP.EXE                A stand alone help browser.
PROC2MOD.EXE            Converts process characterization files
                        to Spice3 BSIM1 MOS model definitions.
SCONVERT.EXE            Converts between ascii and binary spice
                        data files (".raw" files).
MULTIDEC.EXE            A utility for decomposing coupled lossy
                        transmission lines into equivalent uncoupled
                        lines.
SPICEPP.EXE		A Spice pre-processor (built into WinSpice3)

LIB\HELPDIR\SPICE.TXT   On-line information for spice3.
LIB\HELPDIR\SPICE.IDX   Index for spice.txt, generated with
                        the program "makeidx.exe".

LIB\SCRIPTS\SPINIT      Spice/nutmeg commands executed at startup.
LIB\SCRIPTS\SETPLOT     A script for the command "setplot".
LIB\NEWS                A start up message of your choosing.
LIB\MODELS\ZMODELS.LIB	A device model library from Zetex

DOC\SPICEMAN.DOC        A SPICE manual in Word format
DOC\TUTORIAL\*.*	A tutorial in Word format and some example files

EXAMPLES\*.CIR          Lots of circuit examples
LIB\                    Utility scripts and help files

DEMO                    Demo script
DEMO.CIR                Demo circuit (run from DEMO script)
DEMO1.CIR               Demo circuit (run from DEMO script)
DEMO2.CIR               Demo circuit (run from DEMO script)
LF156                   Opamp model used by the demo


Devices and Analyses supported in WinSpice3
-------------------------------------------

For reference, the following is a list of all devices and their
common abbreviation in WinSpice3:

        asrc:   arbitrary voltage/current source
        bjt:    bipolar junction transistor
        bsim1:  detailed MOS model
        bsim2:  detailed MOS model, revised version of bsim1
        cap:    capacitor
        cccs:   current-controlled current source
        ccvs:   current-controlled voltage source
        csw:    current controlled switch
        dio:    diode
        ltra:   lossy transmission line
        ind:    inductor
        isrc:   current source
        jfet:   Junction FET
        mes:    MES FET (GaAs)
        mos1:   MOS, simplest analytic model, fastest
        mos2:   MOS, middle complexity and accuracy
        mos3:   MOS, most complicated, most accurate
        mos6:   MOS, new, fast analytic, short-channel
        res:    resistor
        sw:     switch
        tra:    lossless transmission line
        urc:    uniform RC line
        vccs:   voltage-controlled current source
        vcvs:   voltage-controlled voltage source
        vsrc:   voltage source

The following is the corresponding list of analyses:

        op:     DC operating point
        dc:     DC transfer curve
        tf:     Small signal transfer function
        ac:     AC (frequency domain)
        tran:   transient
        pz:     pole-zero
        disto:  distortion
        noise:  noise
        sense:  sensitivity

