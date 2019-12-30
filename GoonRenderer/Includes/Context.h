#pragma once

#include <unordered_map>
#include <stack>

#include "Singleton.h"
#include "DataType.h"
#include "HeaderPrerequistes.h"

namespace gr
{
    /*
    *   This class manages whole resources which are generated during on simulating rendering pipeline.
    */
    class Context : public Singleton<Context>
    {
    private:
        std::unordered_map<GoonID, Resource*> resources;
        std::stack<GoonID> idStack;
    public:
        Context(int numResLimit=100);
        ~Context() noexcept;
    public:
        /*
         * @brief   generate pointer with given variadic template parameters which is inherited by resource class.  
         *          assign ID to it and insert the id, pointer pair to the resource map.
         *          After assigning, load the resource with initialized it's member variable.
         * @tparam  Type
         * @tparam  Args... template variadic parameters which will be used for constructing Type instance.
        */
        template <typename Type, typename... Args>
        Type* generateResource(Args&&... args) noexcept
        {
            //! generate resource with given type which must be a class inherited by Resource class.
            //! And load that resource with it's initialized member variables.
            Resource* res = new Type(std::forward<Args>(args)...);
            res->load();
            //! pop id from the stack which will be used as identification of the resource.
            GoonID id = idStack.top();
            idStack.pop();
            //! insert the pair of id and resource pointer to resource map.
            resources.insert(std::make_pair(id, res));
            return res;
        }
        /*
         * @brief   get ID from the given resource pointer, with it, find iterator from resource map.
         *          if it exists, get unload resource and deallocate pointer. It's id is pushed to stack again.
         * @param   Resource pointer which will be unloaded and deallocated.
         */
        void destroyResource(Resource* res) noexcept;
    };
};