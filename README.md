# MIPS-Simulator


This simulator for a MIPS processor is broken down into 3 parts:

Part 1:

At this phase of development, the simulator can correctly decode and execute the
complete subset of MIPS instructions specified in the file "MIPS ISA Map". The
simulator can also read in a program from a QtSpim log file that uses the subset
and execute it. Running the simulator on these files will output the dynamic
instruction counts by individual instruction type (ITOKEN) and execution type
(XTYPE).


Part 2:

At this phase of development, the simulator can execute ELF files (extendable,
linkable format), which is the standard format used for object (.o) files and
executable (e.g. a.out) files. These files are compiled from C using the
CodeSourcery MIPS cross-compiler. For this phase of the simulator, a direct-mapped
cache is utilized for both the iCache and dCache. The user can specify the index
size and block size for both the iCache and dCache when executing the simulator
from the command line.


Part 3:

At this phase of development, the simulator executes the same files as Part 2, using
the CodeSourcery MIPS cross-compiler. However, this phase of the simulator utilizes
an n-way set-associative cache for both the iCache and dCache. The user can specify
the index size, block size, and the n-ways for the set-associative iCache and dCache.