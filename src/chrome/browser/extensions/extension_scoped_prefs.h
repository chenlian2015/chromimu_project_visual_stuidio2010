// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_EXTENSIONS_EXTENSION_SCOPED_PREFS_H_
#define CHROME_BROWSER_EXTENSIONS_EXTENSION_SCOPED_PREFS_H_

class ExtensionScopedPrefs {
 public:
  ExtensionScopedPrefs() {}
  ~ExtensionScopedPrefs() {}

  // Sets the pref |key| for extension |id| to |value|.
  virtual void UpdateExtensionPref(const std::string& id,
                                   const std::string& key,
                                   base::Value* value) = 0;

  // Deletes the pref dictionary for extension |id|.
  virtual void DeleteExtensionPrefs(const std::string& id) = 0;

  // Reads a boolean pref |pref_key| from extension with id |extension_id|.
  virtual bool ReadPrefAsBoolean(const std::string& extension_id,
                                 const std::string& pref_key,
                                 bool* out_value) const = 0;

  // Reads an integer pref |pref_key| from extension with id |extension_id|.
  virtual bool ReadPrefAsInteger(const std::string& extension_id,
                                 const std::string& pref_key,
                                 int* out_value) const = 0;

  // Reads a string pref |pref_key| from extension with id |extension_id|.
  virtual bool ReadPrefAsString(const std::string& extension_id,
                                const std::string& pref_key,
                                std::string* out_value) const = 0;

  // Reads a list pref |pref_key| from extension with id |extension_id|.
  virtual bool ReadPrefAsList(const std::string& extension_id,
                              const std::string& pref_key,
                              const base::ListValue** out_value) const = 0;

  // Reads a dictionary pref |pref_key| from extension with id |extension_id|.
  virtual bool ReadPrefAsDictionary(
      const std::string& extension_id,
      const std::string& pref_key,
      const base::DictionaryValue** out_value) const = 0;
};

#endif  // CHROME_BROWSER_EXTENSIONS_EXTENSION_SCOPED_PREFS_H_
