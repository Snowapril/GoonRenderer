#pragma once 

#include "DataType.h"

namespace gr
{
    class Resource
    {
    protected:
        GoonID id = 0U;
    public:
        Resource() = default;
        Resource(GoonID id) : id(id) {};
        virtual ~Resource() {};
    public:
        virtual void load() = 0;
        virtual void unload() = 0;

        inline GoonID getID() noexcept
        {
            return this->id;
        }
    };
};