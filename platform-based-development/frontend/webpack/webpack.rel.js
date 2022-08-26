const { merge } = require("webpack-merge");
const commonConfig = require("./webpack.common");

const BeautifyHtmlWebpackPlugin = require("beautify-html-webpack-plugin");

const prodConfig = {
  mode: "none",
  optimization: {
    minimize: false,
  },
  plugins: [new BeautifyHtmlWebpackPlugin()],
};

module.exports = merge(commonConfig, prodConfig);
