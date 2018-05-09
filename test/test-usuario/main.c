#include <stdio.h>
#include "fct.h"
#include "test_users.h"

FCT_BGN()
    {
        FCT_SUITE_BGN(Buscador del ID en los Usuarios)
        {
            FCT_TEST_BGN(Test_Estructura_Vacia: no se cumpla la condicion del bucle)
            {
                vUsuarios users;
                users.user = NULL;
                users.tam  = 0;
                fct_chk( users.user == NULL );
                fct_chk( users.tam == 0 );
                fct_chk_eq_int( buscarIndexUsuario(&users, 0), -1);
            }
            FCT_TEST_END();

        FCT_TEST_BGN(Test_Primer_Intento: se realiza una unica iteracion)
        {
            vUsuarios users;
            users.user=initUsuarios(&users.tam, "prueba2.txt");
            fct_chk( users.user != NULL );
            fct_chk( users.tam == 12 );
            fct_chk_eq_int( buscarIndexUsuario(&users, 1), 0);
            saveUsuarios(users.tam, users.user, "prueba2.txt");
            free(users.user);
        }
        FCT_TEST_END();

        FCT_TEST_BGN(Test_Segundo_Intento: se realizan dos iteraciones)
        {
            vUsuarios users;
            users.user=initUsuarios(&users.tam, "prueba3.txt");
            fct_chk( users.user != NULL );
            fct_chk( users.tam == 12 );
            fct_chk_eq_int( buscarIndexUsuario(&users, 3), 1);
            saveUsuarios(users.tam, users.user, "prueba3.txt");
            free(users.user);
        }
        FCT_TEST_END();

        FCT_TEST_BGN(Test_cualquiera: se realizan m<n iteraciones)
        {
            vUsuarios users;
            users.user=initUsuarios(&users.tam, "prueba4.txt");
            fct_chk( users.user != NULL );
            fct_chk( users.tam == 12 );
            fct_chk_eq_int( buscarIndexUsuario(&users, 9999), 8);
            saveUsuarios(users.tam, users.user, "prueba4.txt");
            free(users.user);
        }
        FCT_TEST_END();

        FCT_TEST_BGN(Test_Extremos1: se realizan n-1 iteraciones)
        {
            vUsuarios users;
            users.user=initUsuarios(&users.tam, "prueba5.txt");
            fct_chk( users.user != NULL );
            fct_chk( users.tam == 12 );
            fct_chk_eq_int( buscarIndexUsuario(&users, 5201), 10);
            saveUsuarios(users.tam, users.user, "prueba5.txt");
            free(users.user);
        }
        FCT_TEST_END();

        FCT_TEST_BGN(Test_Extremos2: se realizan n iteraciones)
        {
            vUsuarios users;
            users.user=initUsuarios(&users.tam, "prueba5.txt");
            fct_chk( users.user != NULL );
            fct_chk( users.tam == 12 );
            fct_chk_eq_int( buscarIndexUsuario(&users, 1000), 11);
            saveUsuarios(users.tam, users.user, "prueba5.txt");
            free(users.user);
        }
        FCT_TEST_END();

        FCT_TEST_BGN(Test_Extremos3: se realizan n+1 iteraciones)
        {
            vUsuarios users;
            users.user=initUsuarios(&users.tam, "prueba5.txt");
            fct_chk( users.user != NULL );
            fct_chk( users.tam == 12 );
            fct_chk_eq_int( buscarIndexUsuario(&users, 1010), -1);
            saveUsuarios(users.tam, users.user, "prueba5.txt");
            free(users.user);
        }
        FCT_TEST_END();
    }
    FCT_SUITE_END();
}
FCT_END();
