#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"
#include "spdlog/sinks/rotating_file_sink.h"

extern "C" 
{

static std::shared_ptr<spdlog::logger> rotating_logger = nullptr;

void log_init(const char* log_name, const char* log_file, int file_max_size, int max_files) noexcept
{
    rotating_logger = spdlog::rotating_logger_mt(log_name, log_file, file_max_size, max_files);
}

void set_log_level(spdlog::level::level_enum level) noexcept
{
    rotating_logger->set_level(level);
}

void log_info(const char *msg) noexcept
{
    rotating_logger->info(msg);
}

void log_debug(const char *msg) noexcept
{
    rotating_logger->debug(msg);
}

void log_warn(const char *msg) noexcept
{
    rotating_logger->warn(msg);
}

void log_error(const char *msg) noexcept
{
    rotating_logger->error(msg);
}

void log_critical(const char *msg) noexcept
{
    rotating_logger->critical(msg);
}

void log_shutdown() noexcept
{
    spdlog::shutdown();
}
}