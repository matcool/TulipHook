#include "Handler.hpp"
#include "Misc.hpp"
#include "Pool.hpp"
#include "platform/PlatformTarget.hpp"

#include <TulipHook.hpp>

using namespace tulip::hook;

Result<HandlerHandle> tulip::hook::createHandler(void* address, HandlerMetadata const& metadata) noexcept {
	return Pool::get().createHandler(address, metadata);
}

Result<> tulip::hook::removeHandler(HandlerHandle const& handler) noexcept {
	TULIP_HOOK_UNWRAP(Pool::get().removeHandler(handler));
	return Ok();
}

HookHandle tulip::hook::createHook(HandlerHandle const& handler, void* function, HookMetadata const& metadata) noexcept {
	return Pool::get().getHandler(handler).createHook(function, metadata);
}

void tulip::hook::removeHook(HandlerHandle const& handler, HookHandle const& hook) noexcept {
	Pool::get().getHandler(handler).removeHook(hook);
}

void tulip::hook::updateHookMetadata(
	HandlerHandle const& handler, HookHandle const& hook, HookMetadata const& metadata
) noexcept {
	Pool::get().getHandler(handler).updateHookMetadata(hook, metadata);
}

Result<> tulip::hook::writeMemory(void* destination, void const* source, size_t size) noexcept {
	return PlatformTarget::get().writeMemory(destination, source, size);
}

Result<void*> tulip::hook::followJumps(void* address) noexcept {
	return Misc::followJumps(address);
}