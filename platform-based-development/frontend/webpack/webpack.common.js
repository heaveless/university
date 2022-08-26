const path = require("path");

const HtmlWebpackPlugin = require("html-webpack-plugin");

module.exports = {
  entry: {
    main: path.resolve("./src/index.js"),
  },
  output: {
    publicPath: "/",
  },
  resolve: {
    extensions: [".js", ".html"],
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: "./public/index.html",
      //   favicon: "./src/assets/favicon.ico",
    }),
  ],
};
