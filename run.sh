#!/bin/sh
make
cd test/test-viajes && make run
cd ../testacceso && make run
cd ../testincidencia && make run
cd ../testusuario && make run
