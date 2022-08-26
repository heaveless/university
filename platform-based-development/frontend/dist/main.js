/******/ (() => { // webpackBootstrap
/******/ 	"use strict";
var __webpack_exports__ = {};
// This entry need to be wrapped in an IIFE because it uses a non-standard name for the exports (exports).
(() => {
var exports = __webpack_exports__;

 

 var regExpChars = /[|\\{}()[\]^$+*?.]/g;
 var hasOwnProperty = Object.prototype.hasOwnProperty;
 var hasOwn = function (obj, key) { return hasOwnProperty.apply(obj, [key]); };
 
 exports.escapeRegExpChars = function (string) {
   // istanbul ignore if
   if (!string) {
     return '';
   }
   return String(string).replace(regExpChars, '\\$&');
 };
 
 var _ENCODE_HTML_RULES = {
   '&': '&amp;',
   '<': '&lt;',
   '>': '&gt;',
   '"': '&#34;',
   "'": '&#39;'
 };
 var _MATCH_HTML = /[&<>'"]/g;
 
 function encode_char(c) {
   return _ENCODE_HTML_RULES[c] || c;
 }
 
 /**
  * Stringified version of constants used by {@link module:utils.escapeXML}.
  *
  * It is used in the process of generating {@link ClientFunction}s.
  *
  * @readonly
  * @type {String}
  */
 
 var escapeFuncStr =
   'var _ENCODE_HTML_RULES = {\n'
 + '      "&": "&amp;"\n'
 + '    , "<": "&lt;"\n'
 + '    , ">": "&gt;"\n'
 + '    , \'"\': "&#34;"\n'
 + '    , "\'": "&#39;"\n'
 + '    }\n'
 + '  , _MATCH_HTML = /[&<>\'"]/g;\n'
 + 'function encode_char(c) {\n'
 + '  return _ENCODE_HTML_RULES[c] || c;\n'
 + '};\n';
 
 /**
  * Escape characters reserved in XML.
  *
  * If `markup` is `undefined` or `null`, the empty string is returned.
  *
  * @implements {EscapeCallback}
  * @param {String} markup Input string
  * @return {String} Escaped string
  * @static
  * @private
  */
 
 exports.escapeXML = function (markup) {
   return markup == undefined
     ? ''
     : String(markup)
       .replace(_MATCH_HTML, encode_char);
 };
 exports.escapeXML.toString = function () {
   return Function.prototype.toString.call(this) + ';\n' + escapeFuncStr;
 };
 
 /**
  * Naive copy of properties from one object to another.
  * Does not recurse into non-scalar properties
  * Does not check to see if the property has a value before copying
  *
  * @param  {Object} to   Destination object
  * @param  {Object} from Source object
  * @return {Object}      Destination object
  * @static
  * @private
  */
 exports.shallowCopy = function (to, from) {
   from = from || {};
   if ((to !== null) && (to !== undefined)) {
     for (var p in from) {
       if (!hasOwn(from, p)) {
         continue;
       }
       if (p === '__proto__' || p === 'constructor') {
         continue;
       }
       to[p] = from[p];
     }
   }
   return to;
 };
 
 /**
  * Naive copy of a list of key names, from one object to another.
  * Only copies property if it is actually defined
  * Does not recurse into non-scalar properties
  *
  * @param  {Object} to   Destination object
  * @param  {Object} from Source object
  * @param  {Array} list List of properties to copy
  * @return {Object}      Destination object
  * @static
  * @private
  */
 exports.shallowCopyFromList = function (to, from, list) {
   list = list || [];
   from = from || {};
   if ((to !== null) && (to !== undefined)) {
     for (var i = 0; i < list.length; i++) {
       var p = list[i];
       if (typeof from[p] != 'undefined') {
         if (!hasOwn(from, p)) {
           continue;
         }
         if (p === '__proto__' || p === 'constructor') {
           continue;
         }
         to[p] = from[p];
       }
     }
   }
   return to;
 };
 
 /**
  * Simple in-process cache implementation. Does not implement limits of any
  * sort.
  *
  * @implements {Cache}
  * @static
  * @private
  */
 exports.cache = {
   _data: {},
   set: function (key, val) {
     this._data[key] = val;
   },
   get: function (key) {
     return this._data[key];
   },
   remove: function (key) {
     delete this._data[key];
   },
   reset: function () {
     this._data = {};
   }
 };
 
 /**
  * Transforms hyphen case variable into camel case.
  *
  * @param {String} string Hyphen case string
  * @return {String} Camel case string
  * @static
  * @private
  */
 exports.hyphenToCamel = function (str) {
   return str.replace(/-[a-z]/g, function (match) { return match[1].toUpperCase(); });
 };
 
 /**
  * Returns a null-prototype object in runtimes that support it
  *
  * @return {Object} Object, prototype will be set to null where possible
  * @static
  * @private
  */
 exports.createNullProtoObjWherePossible = (function () {
   if (typeof Object.create == 'function') {
     return function () {
       return Object.create(null);
     };
   }
   if (!({__proto__: null} instanceof Object)) {
     return function () {
       return {__proto__: null};
     };
   }
   // Not possible, just pass through
   return function () {
     return {};
   };
 })();
 
 
 
})();

/******/ })()
;