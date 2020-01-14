#pragma once

#include <vector>
#include <stack>

#include "Singleton.h"
#include "DataType.h"
#include "Resource/Resource.h"
#include "HeaderPrerequistes.h"
#include "Buffer.h"

namespace gr
{
    /*
    *   This class manages whole resources which are generated during on simulating rendering pipeline.
    */
    class Context : public Singleton< Context >
    {
    private:
        std::vector<Resource*> resources;
        std::stack<GoonID> idStack;
    public:
        Context(int numResLimit=100);
        ~Context() noexcept;
    public:
        /*
         * @brief get resource with id reinterpreted as required object type.
         * @tparam Type 
        */
        template <typename Type>
        Type* getResource(GoonID id) noexcept;
        /*
         * @brief   generate pointer with given variadic template parameters which is inherited by resource class.  
         *          assign ID to it and insert the id, pointer pair to the resource map.
         *          After assigning, load the resource with initialized it's member variable.
         * @tparam  Type
         * @tparam  Args... template variadic parameters which will be used for constructing Type instance.
        */
        template <typename Type, typename... Args>
        Type* generateResource(Args&&... args) noexcept;
        /*
         * @brief   get ID from the given resource pointer, with it, find iterator from resource map.
         *          if it exists, get unload resource and deallocate pointer. It's id is pushed to stack again.
         * @param   Resource pointer which will be unloaded and deallocated.
         */
        void destroyResource(Resource* res) noexcept;
    };
};

//! Definitions of Context's template methods below.
namespace gr
{
    template <typename Type>
    Type* Context::getResource(GoonID id) noexcept
    {
        //! get resource pointer with id
        Resource* res = resources[id];
        //! it given pointer matched with id is nullptr, return nullptr
        //! otherwise downcasting to required type
        return res == nullptr ? nullptr : (Type*)(&res);
    }

    template <typename Type, typename... Args>
    Type* Context::generateResource(Args&&... args) noexcept
    {
        //! pop id from the stack which will be used as identification of the resource.
        GoonID id = idStack.top();
        idStack.pop();
        //! generate resource with given type which must be a class inherited by Resource class.
        //! And load that resource with it's initialized member variables.
        resources[id] = new Type(std::forward<Args>(args)...);
        resources[id]->load();
        
        return (Type*)(&resources[id]);
    }
};