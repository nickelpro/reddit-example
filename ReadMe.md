# reddit-example

Example of building an object library to be statically linked into another
library from the build tree, without re-exporting that object library.

Note, in this example the `Util` library target is built as an `OBJECT` library
since we have no intention of exporting it as a standalone library. That said
this can be changed to `STATIC` if you desire the fully linked artifact to
be present in the build tree. There is no advantage to this and simply makes
the build take longer.
