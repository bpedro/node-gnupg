{
  "targets": [
    {
      "target_name": "gnupg",
      "sources": ["src/gnupg.cc"],
      "cflags_cc" : ["-O3", "-fexceptions"],
      "libraries": ["-lgpgme"],
    }
  ]
}