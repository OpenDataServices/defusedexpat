/* Stuff to export relevant 'expat' entry points from pyexpat to other
 * parser modules, such as cElementTree. */

/* note: you must import expat.h before importing this module! */

#ifdef XML_BOMB_PROTECTION
#define PyExpat_CAPI_MAGIC  "pyexpat.expat_CAPI 1.1 bomb protection"
#else
#define PyExpat_CAPI_MAGIC  "pyexpat.expat_CAPI 1.0"
#endif
#define PyExpat_CAPSULE_NAME "pyexpat.expat_CAPI"

struct PyExpat_CAPI 
{
    char* magic; /* set to PyExpat_CAPI_MAGIC */
    int size; /* set to sizeof(struct PyExpat_CAPI) */
    int MAJOR_VERSION;
    int MINOR_VERSION;
    int MICRO_VERSION;
    /* pointers to selected expat functions.  add new functions at
       the end, if needed */
    const XML_LChar * (*ErrorString)(enum XML_Error code);
    enum XML_Error (*GetErrorCode)(XML_Parser parser);
    XML_Size (*GetErrorColumnNumber)(XML_Parser parser);
    XML_Size (*GetErrorLineNumber)(XML_Parser parser);
    enum XML_Status (*Parse)(
        XML_Parser parser, const char *s, int len, int isFinal);
    XML_Parser (*ParserCreate_MM)(
        const XML_Char *encoding, const XML_Memory_Handling_Suite *memsuite,
        const XML_Char *namespaceSeparator);
    void (*ParserFree)(XML_Parser parser);
    void (*SetCharacterDataHandler)(
        XML_Parser parser, XML_CharacterDataHandler handler);
    void (*SetCommentHandler)(
        XML_Parser parser, XML_CommentHandler handler);
    void (*SetDefaultHandlerExpand)(
        XML_Parser parser, XML_DefaultHandler handler);
    void (*SetElementHandler)(
        XML_Parser parser, XML_StartElementHandler start,
        XML_EndElementHandler end);
    void (*SetNamespaceDeclHandler)(
        XML_Parser parser, XML_StartNamespaceDeclHandler start,
        XML_EndNamespaceDeclHandler end);
    void (*SetProcessingInstructionHandler)(
        XML_Parser parser, XML_ProcessingInstructionHandler handler);
    void (*SetUnknownEncodingHandler)(
        XML_Parser parser, XML_UnknownEncodingHandler handler,
        void *encodingHandlerData);
    void (*SetUserData)(XML_Parser parser, void *userData);
    void (*SetStartDoctypeDeclHandler)(XML_Parser parser,
                                       XML_StartDoctypeDeclHandler start);
#ifdef XML_BOMB_PROTECTION
    /* CAPI 1.1 bomb protection additions */
    unsigned int (*GetMaxEntityIndirections)(XML_Parser parser);
    void (*SetMaxEntityIndirections)(XML_Parser parser, unsigned int value);

    unsigned int (*GetEntityExpansions)(XML_Parser parser);
    unsigned int (*GetMaxEntityExpansions)(XML_Parser parser);
    void (*SetMaxEntityExpansions)(XML_Parser parser, unsigned int value);

    XML_Bool (*GetResetDTDFlag)(XML_Parser parser);
    void (*SetResetDTDFlag)(XML_Parser parser, XML_Bool value);
#endif
    /* always add new stuff to the end! */
};

