Kollector - Collections builder for Kindle
==========================================

Kollector is a simple automatic collections manager. It will help you organize books on the Kindle
device by creating collections based on the directory structure of documents. For a quick peek of
this functionality, see the example below.

Given the directory structure as follows

	documents
	|-- George Orwell
	|   |-- A Clergyman's Daughter.mobi
	|   `-- Nineteen Eighty-Four.mobi
	`-- Stephen Hawking
	    `-- A Brief History of Time.mobi

by default this utility will create one collection based on the directory named "George Orwell".
The "Stephen Hawking" directory will not trigger collection creation, because it contains only one
book. Such a behavior can be changed by using the command line argument `-s` - run `kollector -h`
for more information.


Compilation
-----------

	$ autoreconf --install
	$ mkdir build && cd build
	$ export KINDLE_ROOTDIR=<absolute_patch_to_the_Kindle_root_directory>
	$ ../configure --enable-kindle-env --host=armv7a-softfp-linux-gnueabi
	$ make


Similar projects
----------------

1. [KTCollectionsMgr](https://bitbucket.org/NiLuJe/ktcollectionsmgr) - GUI-based collections
	 manager
