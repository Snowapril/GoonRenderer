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
        virtual ~Resource() = 0;
    public:
        virtual void load() noexcept = 0;
        virtual void unload() noexcept = 0;

        inline GoonID getID() noexcept
        {
            return this->id;
        }
    };
};