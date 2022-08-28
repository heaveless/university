module.exports = {
  env: {
    browser: true,
    es6: true,
  },
  parser: "@typescript-eslint/parser",
  extends: ["preact", "plugin:@typescript-eslint/recommended", "standard-jsx"],
  globals: {
    Atomics: "readonly",
    SharedArrayBuffer: "readonly",
    totalPrice: "readonly",
    cartItems: "readonly",
  },
  parserOptions: {
    ecmaVersion: 2018,
    sourceType: "module",
    ecmaFeatures: {
      experimentalObjectRestSpread: true,
      jsx: true,
    },
  },
  rules: {
    indent: ["error", 2],
    "linebreak-style": ["error", "unix"],
    quotes: ["error", "single"],
    semi: ["error", "never"],
    "react/jsx-no-bind": [
      "error",
      {
        allowArrowFunctions: true,
        allowBind: false,
        ignoreRefs: true,
      },
    ],
    "react/react-in-jsx-scope": "error",
    "jsx-quotes": ["error", "prefer-double"],
  },
  plugins: ["react"],
  ignorePatterns: ["build/"],
};
