#!/bin/sh
make
cd test/test-viajes && make run
cd ../test-acceso && make run
cd ../test-incidencia && make run
cd ../test-usuario && make run
