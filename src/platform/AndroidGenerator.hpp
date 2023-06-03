#pragma once

#include "../Generator.hpp"

#include <Platform.hpp>

#if defined(TULIP_HOOK_ANDROID)

namespace tulip::hook {

	class AndroidHandlerGenerator : public HandlerGenerator {
	public:
		using HandlerGenerator::HandlerGenerator;

		Result<> generateHandler() override {
            return Err("unimpl");
        }
		Result<std::vector<uint8_t>> generateIntervener() override {
            return Err("unimpl");
        }
		Result<> generateTrampoline(RelocateReturn offsets) override {
            return Err("unimpl");
        }
		Result<RelocateReturn> relocateOriginal(uint64_t target) override {
            return Err("unimpl");
        }

		std::string handlerString() override { return "umm ☻"; }
		std::string intervenerString() override { return "umm ☻"; }
		std::string trampolineString(size_t offset) override { return "umm ☻"; }

		void relocateInstruction(cs_insn* insn, uint64_t& trampolineAddress, uint64_t& originalAddress) override {}
	};

	using PlatformHandlerGenerator = AndroidHandlerGenerator;

	class AndroidWrapperGenerator : public WrapperGenerator {
	public:
		using WrapperGenerator::WrapperGenerator;

		Result<void*> generateWrapper() override {
            return Err("unimpl");
        }
		Result<void*> generateReverseWrapper() override {
            return Err("unimpl");
        }

		std::string wrapperString() override { return "umm ☻"; }
		std::string reverseWrapperString() override { return "umm ☻"; }
	};

	using PlatformWrapperGenerator = AndroidWrapperGenerator;
}

#endif