{
    "targets": [
        {
            "target_name": "libadaptivecards_objc",
            "type": 'static_library',
            "dependencies": [
              "./deps/djinni/support-lib/support_lib.gyp:djinni_objc",
            ],
            'direct_dependent_settings': {

            },
            "sources": [
		
              "<!@(python deps/djinni/example/glob.py generated-src/objc  '*.cpp' '*.mm' '*.m' ‘*.m’)",
              "<!@(python deps/djinni/example/glob.py generated-src/cpp   '*.cpp' '*.m')",
              "<!@(python deps/djinni/example/glob.py src '*.cpp')",
            ],
            "include_dirs": [
              "generated-src/objc",
              "generated-src/cpp",
              "../Shared/ObjectModel",
              "src",
            ],
        },
    ],
}
