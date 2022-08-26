const { merge } = require("webpack-merge");
const commonConfig = require("./webpack.common");

const BeautifyHtmlWebpackPlugin = require("beautify-html-webpack-plugin");

const devConfig = {
  mode: "development",
  devtool: "inline-source-map",
  devServer: {
    port: 3000,
    historyApiFallback: true,
    allowedHosts: "all",
  },
  optimization: {
    minimize: false,
  },
  plugins: [new BeautifyHtmlWebpackPlugin()],
};

module.exports = merge(commonConfig, devConfig);
