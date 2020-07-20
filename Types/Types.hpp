#ifndef __TYPES_H__
#define __TYPES_H__

#include <string>
#include <map>
#include <iostream>
#include <functional>

namespace quick {
    /**
     * INTEGERS TYPES
     * 
     */
    typedef char            c8;
    typedef unsigned char   u8;
    typedef signed char     s8;
    typedef unsigned short  u16;
    typedef signed short    s16;
    typedef unsigned int    u32;
    typedef signed int      s32;
    typedef unsigned long   u64;
    typedef signed long     s64;

    /**
     * FLOATING TYPES
     * 
     */
    typedef float           f32;
    typedef double          f64;

    /**
     * POINTER AND STRING TYPES
     * 
     */
    typedef void *          ptr;
    typedef char *          cstr;

    /**
     * OTHER TYPE REDEFINITIONS
     * 
     * byte:    Used when processing a variable byte by byte.
     * size:    Used when computing size of a string or any variable.
     * ssize:   Same as size but signed value.
     * hash:    Used to store hash value.
     * fd:      Used to store file descriptor value.
     * status:  Used to store return value of a function
     *          (If someting failed during its execution for instance).  
     */
    typedef char            byte;
    typedef unsigned long   size;
    typedef signed long     ssize;
    typedef unsigned long   hash;
    typedef int             fd;
    typedef short           status;

    /**
     * All quick library class inherits from quickObject class.
     */
    class quickObject;
};


typedef std::pair<std::string, std::string> FObjStrWrap_t;

#define FOBJ_STR "quickObject"
#define FOBJ_TYPE_WRAP FObjStrWrap_t("<", ">")
#define FOBJ_DESC_WRAP FObjStrWrap_t("{", "}")
#define FOBJ_DESC_DELIM ","

class quickObject
{
    public:
        typedef std::function<const std::string &(void *)> showFun_t;
        typedef std::pair<showFun_t, void *> attribute_t;
        typedef std::map<std::string, attribute_t> attributeList_t;

        virtual ~quickObject();

        const std::string &getObjectName() const
        {
            return _typeName;
        }
        const attributeList_t &getAtributes() const
        {
            return _attributes;
        }
    
    protected:
        std::string _typeName;
        attributeList_t _attributes;
};

std::ostream &operator<<(std::ostream &s, const quickObject &object)
{
    quickObject::attributeList_t attributes = object.getAtributes();

    s << FOBJ_TYPE_WRAP.first << FOBJ_STR << " : " << object.getObjectName() << FOBJ_TYPE_WRAP.second;
    s << " = " << FOBJ_DESC_WRAP.first;

    for (quickObject::attributeList_t::iterator i = attributes.begin(); i != attributes.end(); i++) {
        s << i->first << ": " << i->second.first(i->second.second);
        if (i != (std::next(attributes.begin(), attributes.size() - 2)))
            s << FOBJ_DESC_DELIM;
    }
    s << FOBJ_DESC_WRAP.second;
}

#endif