#ifndef PREPROCESSOR_3223
#define PREPROCESSOR_3223

#define ARG_1(A,...) A
#define ARG_2(A,B,...) B
#define ARG_3(A,B,C,...) C
#define ARG_4(A,B,C,D,...) D
#define ARG_5(A,B,C,D,E,...) E
#define ARG_6(A,B,C,D,E,F,...) F
#define ARG_7(A,B,C,D,E,F,G,...) G
#define ARG_8(A,B,C,D,E,F,G,H,...) H
#define ARG_9(A,B,C,D,E,F,G,H,I,...) I

#define PASTE(x,y) PASTE_(x,y)
#define PASTE_(x,y) x##y

#endif

