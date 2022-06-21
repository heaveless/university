#include <iostream>

// int compare(const char *s1, const char *s2) {
//    while (*s1 != '\0' && *s2 != '\0'  && *s1 == *s2) {
//       s1++;
//       s2++;
//    }
//    return *s1 - *s2;
// }
//
// char* concat(char *dest, const char *src, size_t size) {
//     size_t idx = 0;
//     for (; idx < size && src[idx] != '\0'; idx++) {
//         dest[idx] = src[idx];
//     }
//
//     for (; idx < size; idx++) {
//         dest[idx] = '\0';
//     }
//
//     return dest;
// }
//
// char* split(char* str, const char* spliter) {
//     static char* s = NULL;
//     char* tok;
//     if(str == NULL) {
//         if(s == NULL)
//             return NULL;
//         } else
//     s = str;
//     for(size_t i; (*s != '\0'); s++) {
//         for(i = 0; (spliter[i] != '\0') && (*s != spliter[i]); i++);
//             if(spliter[i] == '\0')
//                 break;
//     }
//     if(*s == '\0')
//         return s = NULL;
//     tok = s++;
//     for(size_t i; (*s != '\0'); s++) {
//         for(i = 0; (spliter[i] != '\0') && (*s != spliter[i]); i++);
//             if(spliter[i] != '\0')
//                 break;
//     }
//         if(*s != '\0') {
//             *s = '\0';
//             s++;
//         }
//     return tok;
// }


void divider(const char* current) {
  std::cout << *current << std::endl;
}

bool checker(const char* current, const char* tarjet) {
  while (*current != '\0' && *tarjet != '\0'  && *current == *tarjet) {
    current++;
    tarjet++;
  }

  return *tarjet == '\0';
}

int main()
{
  const int wordSize = 20;
  const int totalSize = 300;

  const char stopword[totalSize / wordSize][wordSize] = { "is", "not", "that", "there", "are", "many", "can", "you", "with", "one", "of", "those", ".", ",", ";" };
  const char text[] = "feature extraction is not that complex. there are many algorithms available that can help you with feature extraction. rapid automatic keyword extraction is one of those.";
  
  const char (*stopwordPtr)[wordSize] = stopword;
  const char* textPtr = text;
  int stopwordSize = sizeof(stopword)/sizeof(*stopword);

  // checker(textPtr, *stopwordPtr);
  // stopwordPtr++;
  // checker(textPtr, *stopwordPtr);

  //
 
  //  && stopwordSize
  while(*textPtr != '\0') {
    bool isFound = checker(textPtr, *stopwordPtr);
    if(isFound) {
      divider(textPtr);
      
      // textPtr = text;
    }
    std::cout << isFound << std::endl;
    textPtr++;
    // stopwordSize--;
  }

  // textPtr++;
  // std::cout << *textPtr << std::endl;

  //
  // const char* delimiter[] = {".",",",";"};
  // const char spliter[] = " .";
  

  // std::cout << "Texto Original:\n" << originalText << std::endl;
  //
  // char keyPhrases[totalSize];
  //
  // char* text = split(originalText, spliter);
  //
  // std::cout << "\nCandidate Key Phrases" << std::endl;
  // std::cout << "\033[1;31mbold red text\033[0m\n" << std::endl;
  //
  // int activeChange = 0;
  // while (text != NULL)
  // {
  //   int found = 0;
  //   for(int i = 0; i < size; i++)
  //   {
  //     if (!compare(stopword[i], text)) {
  //       if (!activeChange)
  //         std::cout << ",";
  //       activeChange = 1;
  //       found = 1;
  //       break;
  //     }
  //   }
  //
  //   if (!found) {
  //     std::cout << text << " ";
  //     activeChange = 0;
  //   }
  //
  //   text = split(NULL, spliter);
  // }

  return 0;
}
