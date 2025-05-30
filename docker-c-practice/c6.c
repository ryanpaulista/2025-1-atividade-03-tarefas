int y = 0 ;

void threadBody
{
int x = 0 ;
sleep (10) ;
printf ("x: %d, y:%d\n", ++x, ++y) ;
thread_exit();
}

 main ()
 {
 thread_create (&tA, threadBody, ...) ;
 thread_create (&tB, threadBody, ...) ;
 sleep (1) ;
 thread_join (&tA) ;
 thread_join (&tB) ;
 sleep (1) ;
 thread_create (&tC, threadBody, ...) ;
 thread_join (&tC) ;
 }