#include <node.h>
#include <v8.h>
#include <locale.h>
#include <gpgme.h>

using namespace v8;

void throwError(gpgme_error_t err, const char * msg){
    // run a GPG operation and throw informative errors on GPG errors
    char buff[1024];
    if(err){
        sprintf(buff, "GPG error (%s): %s", gpgme_strerror(err), msg);
        ThrowException(Exception::Error(String::New(buff)));
    }
}

Handle<Value> _notimplementedyet(const Arguments& args) {
    HandleScope scope;
    return scope.Close(String::New("not implemented yet."));
}

Handle<Value> init(const Arguments& args) {
    HandleScope scope;
    /* Initialize the locale environment.  */
    setlocale(LC_ALL, "");
    gpgme_check_version(NULL);
    gpgme_set_locale(NULL, LC_CTYPE, setlocale (LC_CTYPE, NULL));
    #ifdef LC_MESSAGES
        gpgme_set_locale(NULL, LC_MESSAGES, setlocale (LC_MESSAGES, NULL));
    #endif

    // check if
    throwError(gpgme_engine_check_version(GPGME_PROTOCOL_OpenPGP), "test");
    return scope.Close(String::New("initialized"));
}

void initAddon(Handle<Object> exports) {
    exports->Set(
        String::NewSymbol("adddecryptkey"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("addencryptkey"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("addsignkey"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("cleardecryptkeys"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("clearencryptkeys"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("clearsignkeys"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("decrypt"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("decryptverify"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("encrypt"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("encryptsign"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("export"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("geterror"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("getprotocol"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("import"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("init"),
        FunctionTemplate::New(init)->GetFunction());
    exports->Set(
        String::NewSymbol("keyinfo"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("setarmor"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("seterrormode"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("setsignmode"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("sign"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
    exports->Set(
        String::NewSymbol("verify"),
        FunctionTemplate::New(_notimplementedyet)->GetFunction());
}

NODE_MODULE(gnupg, initAddon)