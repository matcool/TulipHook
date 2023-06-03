#pragma once

#include "../Target.hpp"

#include <Platform.hpp>

#if defined(TULIP_HOOK_ANDROID)

namespace tulip::hook {

	class AndroidTarget : public Target {
	public:
		using Target::Target;

		static AndroidTarget& get() {
            static AndroidTarget inst;
            return inst;
        }

		Result<ks_engine*> openKeystone() override {
            return Err("unimpl");
        }
		Result<csh> openCapstone() override {
            return Err("unimpl");
        }

		Result<> allocatePage() override {
            return Err("unimpl");
        }
		Result<uint32_t> getProtection(void* address) override {
            return Err("unimpl");
        }
		Result<> protectMemory(void* address, size_t size, uint32_t protection) override {
            return Err("unimpl");
        }
		Result<> rawWriteMemory(void* destination, void const* source, size_t size) override {
            return Err("unimpl");
        }
		uint32_t getMaxProtection() override {
            return 0;
        }
	};

	using PlatformTarget = AndroidTarget;

}

#endif