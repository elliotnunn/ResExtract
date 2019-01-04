#include <Resources.h>
#include <Strings.h>

int main(int argc, char **argv)
{
    long i, j, k;

    for (i=1; i<argc; i++) c2pstr(argv[i]);

    for (i=1; i<argc; i++) {
        SetResLoad(0); OpenResFile(argv[i]);
        for (j=Count1Types(); j>=1; j--) {
            ResType T; Get1IndType(&T, j);
            for (k=Count1Resources(T); k>=1; k--) {
                Handle H = Get1IndResource(T, k);
                LoadResource(H);
                SetResAttrs(H, GetResAttrs(H) & ~1);
                ChangedResource(H); WriteResource(H);
            }
        }
        CloseResFile(CurResFile());
    }
    return 0;
}
