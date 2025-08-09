#ifndef APP_INFO_H
#define APP_INFO_H

#define APP_VER "1.2"
#define RELEASE_DATE "Αύγουστος 2025"
#define RELEASE_YEAR "2025"
#define LICENSE "MIT"
#define COPYRIGHT_NOTICE "Θάνος Τσουκαλάς και όλοι οι συνεισφέροντες μέχρι την παρούσα έκδοση."

/*
    Τσεκάρουμε την αρχιτεκτονική 
    Κώδικας από: https://stackoverflow.com/a/1505631/22320491
*/ 

#if _WIN32 || _WIN64
#if _WIN64
#define ARCHITECTURE "AMD64 (64-bit)"
#else
#define ARCHITECTURE "x86 (32-bit)"
#endif
#endif

#if __GNUC__
#if __x86_64__
#define ARCHITECTURE "AMD64 (64-bit)"
#else
#define ARCHITECTURE "x86 (32-bit)"
#endif
#endif


#endif 