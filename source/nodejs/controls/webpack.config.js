module.exports = {
    entry: "./src/ms-js-controls.ts",
    output: {
        filename: "./dist/ms-js-controls.js",
        library: 'MsJsControls'
    },

    resolve: {
        extensions: [".webpack.js", ".web.js", ".ts", ".js"]
    },

    module: {
        rules: [
            // All files with a '.ts' or '.tsx' extension will be handled by 'awesome-typescript-loader'.
            {
                test: /\.ts$/,
                loader: "ts-loader",
            },
            {
                test: /\.json$/,
                loader: "json-loader",
            }

        ]
    },
};