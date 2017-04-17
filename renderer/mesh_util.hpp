#pragma once

#include "mesh.hpp"
#include "vulkan_events.hpp"

namespace Granite
{
class CubeMesh : public StaticMesh, public EventHandler
{
public:
	CubeMesh();

private:
	void on_device_created(const Event &event);

	void on_device_destroyed(const Event &event);
};

class Skybox : public AbstractRenderable, public EventHandler
{
public:
	Skybox(std::string bg_path);

	void get_render_info(const RenderContext &context, const CachedSpatialTransformComponent *transform, RenderQueue &queue) const override;

private:
	std::string bg_path;
	Vulkan::Texture *texture = nullptr;
	void on_device_created(const Event &event);

	void on_device_destroyed(const Event &event);
};
}