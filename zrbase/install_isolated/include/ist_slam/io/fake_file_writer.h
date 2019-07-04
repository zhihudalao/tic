/*
 * Copyright 2018 The ist_slam Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IST_SLAM_IO_FAKE_FILE_WRITER_H_
#define IST_SLAM_IO_FAKE_FILE_WRITER_H_

#include <memory>
#include <string>
#include <vector>

#include "ist_slam/io/file_writer.h"

namespace ist_slam {
namespace io {

// Fakes a FileWriter by just writing the data to a std::vector<char>.
class FakeFileWriter : public FileWriter {
 public:
  FakeFileWriter(const std::string& filename,
                 std::shared_ptr<std::vector<char>> content);
  ~FakeFileWriter() override = default;

  bool WriteHeader(const char* data, size_t len) override;
  bool Write(const char* data, size_t len) override;
  bool Close() override;
  std::string GetFilename() override;

 private:
  bool is_closed_;
  std::shared_ptr<std::vector<char>> content_;
  std::string filename_;
};

}  // namespace io
}  // namespace ist_slam

#endif  // IST_SLAM_IO_FAKE_FILE_WRITER_H_
