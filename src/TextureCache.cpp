// Copyright 2024 Jan Niklas Hasse <jhasse@bixense.com>
// For conditions of distribution and use, see copyright notice in LICENSE.txt
#include "TextureCache.hpp"

#include <cassert>

namespace jngl {

std::shared_ptr<Texture> TextureCache::get(std::string_view filename) {
	auto it = textures.find(filename);
	if (it == textures.end()) {
		return nullptr;
	}
	return it->second;
}

void TextureCache::insert(std::string_view filename, std::shared_ptr<Texture> texture) {
	auto result [[maybe_unused]] = textures.emplace(filename, std::move(texture));
	assert(result.second);
}

void TextureCache::remove(std::string_view filename) {
	auto it = textures.find(filename);
	if (it != textures.end()) {
		textures.erase(it);
	}
}

} // namespace jngl
