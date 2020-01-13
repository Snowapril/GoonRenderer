#pragma once

#include <vector>
#include <stack>

#include "Singleton.h"
#include "DataType.h"
#include "HeaderPrerequistes.h"

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