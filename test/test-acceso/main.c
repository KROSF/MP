#include<stdio.h>
#include "fct.h"
#include "acceso.h"

FCT_BGN()
{
    printf("\n------------------------------ TEST ACCESO ------------------------------\n\n");
    FCT_SUITE_BGN(TestAcceso)
    {
        FCT_TEST_BGN(NoSeCumpleLaCondicionDelBucle)
        {
           vUsuarios test;
           test.user = initUsuarios(&test.tam, "Usuarios.txt");
           fct_chk_eq_int(check_user(&test, "usuarioprueba","estonofunciona"),-1);
           saveUsuarios(test.tam, test.user, "Usuarios.txt");
        }
        FCT_TEST_END();
        FCT_TEST_BGN(UnaUnicaIteracion)
        {
           vUsuarios test;
           test.user = initUsuarios(&test.tam, "Usuarios1.txt");
           fct_chk_eq_int(check_user(&test, "krosf","998022"),0);
           saveUsuarios(test.tam, test.user, "Usuarios2.txt");
        }
        FCT_TEST_END();
        FCT_TEST_BGN(DosIteraciones)
        {
           vUsuarios test;
           test.user = initUsuarios(&test.tam, "Usuarios1.txt");
           fct_chk_eq_int(check_user(&test, "usua2","m1909876"),1);
           saveUsuarios(test.tam, test.user, "Usuarios2.txt");
        }
        FCT_TEST_END();
        FCT_TEST_BGN(m < niteraciones)
        {
           vUsuarios test;
           test.user = initUsuarios(&test.tam, "Usuarios1.txt");
           fct_chk_eq_int(check_user(&test, "alva","123456"),3);
           saveUsuarios(test.tam, test.user, "Usuarios2.txt");
        }
        FCT_TEST_END();
        FCT_TEST_BGN(n-1 iteraciones)
        {
           vUsuarios test;
           test.user = initUsuarios(&test.tam, "Usuarios1.txt");
           fct_chk_eq_int(check_user(&test, "mike","2019"),2);
           saveUsuarios(test.tam, test.user, "Usuarios2.txt");
        }
        FCT_TEST_END();
        FCT_TEST_BGN(n iteraciones)
        {
           vUsuarios test;
           test.user = initUsuarios(&test.tam, "Usuarios.txt");
           fct_chk_eq_int(check_user(&test, "usuarioprueba","estonofunciona4"),-1);
           saveUsuarios(test.tam, test.user, "Usuarios.txt");
        }
        FCT_TEST_END();
        FCT_TEST_BGN(n+1 iteraciones)
        {
           vUsuarios test;
           test.user = initUsuarios(&test.tam, "Usuarios.txt");
           fct_chk_eq_int(check_user(&test, "usuarioprueba2","estonofunciona2"),-1);
           saveUsuarios(test.tam, test.user, "Usuarios.txt");
        }
        FCT_TEST_END();
    }
    FCT_SUITE_END();
}
FCT_END();
